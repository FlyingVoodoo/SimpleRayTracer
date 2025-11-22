from PIL import Image
import numpy as np

with open('output.ppm', 'r', encoding='utf-8') as f:
    magic = f.readline().strip()
    size = f.readline().strip()
    maxval = f.readline().strip()
    
    print(f"Magic: {magic}")
    print(f"Size: {size}")
    print(f"Maxval: {maxval}")
    
    width, height = map(int, size.split())
    
    pixels = []
    for line in f:
        pixels.extend(map(int, line.split()))
    
    pixels = np.array(pixels, dtype=np.uint8)
    pixels = pixels.reshape((height, width, 3))
    
    img = Image.fromarray(pixels, 'RGB')
    img.save('output.png')
    print("✓ Конвертация завершена: output.png создан!")
