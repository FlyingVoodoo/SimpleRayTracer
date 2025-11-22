#include "Render.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "utils.hpp"
#include "Lambertian.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <random>
#include <cmath>

void render_region(int start_y, int end_y, int image_width, int image_height, int samples_per_pixel, const Camera& camera, const World& world, std::vector<Vec3d>& framebuffer, int seed) {
    std::mt19937 generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int j = start_y; j < end_y; ++j) {
        for (int i = 0; i < image_width; ++i) {
            Vec3d pixel_color(0.0, 0.0, 0.0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double random_u_offset = distribution(generator);
                double random_v_offset = distribution(generator);

                double u = (i + random_u_offset) / (image_width - 1);
                double v = (j + random_v_offset) / (image_height - 1);

                Rayd r = camera.get_ray(u, v);
                pixel_color = pixel_color + RayColor(r, world, 50);
            }
            framebuffer[j * image_width + i] = pixel_color / static_cast<double>(samples_per_pixel);
        }
    }
}

int main() {
    const int image_width = 800;
    const int image_height = 450;
    const int samples_per_pixel = 1000;
    const int num_threads = std::thread::hardware_concurrency();

    World world;
    auto material_center = std::make_shared<Lambertian>(Color(0.7, 0.3, 0.3));
    world.add(std::make_shared<Sphere>(Vec3d(0.0, 0.0, -1.0), 0.5, material_center));
    auto material_ground = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    world.add(std::make_shared<Sphere>(Vec3d(0.0, -100.5, -1.0), 100.0, material_ground));

    Camera camera;
    std::vector<Vec3d> framebuffer(image_width * image_height);
    std::vector<std::thread> threads;

    int rows_per_thread = image_height / num_threads;

    std::ofstream outfile("output.ppm");
    if (!outfile) {
        std::cerr << "Cannot create output.ppm\n";
        return 1;
    }
    
    outfile << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int k = 0; k < num_threads; ++k) {
        int start_y = k * rows_per_thread;
        int end_y = (k == num_threads - 1) ? image_height : start_y + rows_per_thread;

        threads.emplace_back(render_region, start_y, end_y, image_width, image_height, samples_per_pixel, std::ref(camera), std::ref(world), std::ref(framebuffer), k);
    }

    for (auto& t : threads) {
        t.join();
    }

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            Vec3d pixel_color = framebuffer[j * image_width + i];
            writeColor(outfile, pixel_color, 1);
        }
    }
    
    outfile.close();
    std::cout << "Rendering complete. Output saved to output.ppm\n";

    return 0;
}