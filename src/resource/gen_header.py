import os
import numpy as np
from PIL import Image

here = os.path.dirname(os.path.abspath(__file__))
os.chdir(here)

global_color_table = {
  0: (0,0,0),
  1: (0x0a, 0x08, 0x0d),
  2: (0x69, 0x75, 0x94),
  3: (0xdf, 0xe9, 0xf5),
  4: (0xf7, 0xaa, 0xa8),
  5: (0xd4, 0x68, 0x9a),
  6: (0x78, 0x2c, 0x96),
  7: (0xd4, 0x1c, 0x3d),
  8: (0xf2, 0x82, 0x5c),
  9: (0xff, 0xc7, 0x6e),
  10: (0x88, 0xc4, 0x4d),
  11: (0x3f, 0x9e, 0x59),
  12: (0x37, 0x34, 0x61),
  13: (0x48, 0x54, 0xa8),
  14: (0x71, 0x99, 0xd9),
  15: (0x9e, 0x52, 0x52),
  16: (0x4d, 0x25, 0x36)
}


def transform_file(path):
  i = Image.open("./files/" + path)
  a = np.array(i)
  b = []
  h,w = a.shape[:2]
  for y in range(h):
    for x in range(w):
      rgba_tuple = tuple(a[y, x])
      rgba_tuple = rgba_tuple[:3]
      try:
        b.append(list(global_color_table.keys())[list(global_color_table.values()).index(rgba_tuple)])
      except:
        print(f"Color not found in global color table: {rgba_tuple}")
        raise
      
  name = "RES_" + (path.split('.')[0]).upper()
  width_entry = f"#define {name}_WIDTH {w}\n"
  height_entry = f"#define {name}_HEIGHT {h}\n"
  data_entry = f"#define {name}_DATA {','.join([str(i) for i in b])}\n\n"
  return width_entry + height_entry + data_entry

filename = "res.h"

header = ""

header_header = "#ifndef RES_H\n#define RES_H\n\n\n#define RES_H_TILE_AMOUNT 1\n\n"
header_footer = "\n#endif\n"
content = ""

for root, dirs, files in os.walk(here + "/files"):
  for file in files:
    if file.endswith(".png"):
      content += transform_file(file)

content = header_header + content + header_footer

with open(here + "/" + filename, "w") as f:
  f.write(content)

print(content)

file_stats = os.stat(here + "/" + filename)
print(f'----- fsize: {file_stats.st_size / (1024 * 1024)} MB')
