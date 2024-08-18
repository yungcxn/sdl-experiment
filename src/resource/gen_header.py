import os
import numpy as np
from PIL import Image

here = os.path.dirname(os.path.abspath(__file__))
os.chdir(here)

global_color_table = {
  0: (0,0,0),
  1: (0x0a, 0x08, 0x0d),
  2: (0xdf, 0xe9, 0xf5),
  3: (0xf7, 0xaa, 0xa8),
  4: (0xd4, 0x68, 0x9a),
  5: (0x78, 0x2c, 0x96),
  6: (0xd4, 0x1c, 0x3d),
  7: (0xf2, 0x82, 0x5c),
  8: (0xff, 0xc7, 0x6e),
  9: (0x88, 0xc4, 0x4d),
  10: (0x3f, 0x9e, 0x59),
  11: (0x37, 0x34, 0x61),
  12: (0x48, 0x54, 0xa8),
  13: (0x71, 0x99, 0xd9),
  14: (0x9e, 0x52, 0x52),
  15: (0x4d, 0x25, 0x36)
}
color_to_index = {v: k for k, v in global_color_table.items()}

def rc(l):
  r = []
  i = 0
  while i < len(l):
    count = 1
    while i + count < len(l) and l[i + count] == l[i] and count < 255:
      count += 1
    r.extend([count, l[i]])
    i += count
  return r


def transform_file(path):
  i = Image.open("./files/" + path)
  a = np.array(i)
  b = []
  h,w = a.shape[:2]
  for y in range(h):
    for x in range(0, w, 2):
      rgba_tuple1 = tuple(a[y, x])
      rgba_tuple2 = tuple(a[y, x+1])
      rgb_tuple1 = rgba_tuple1[:3]
      rgb_tuple2 = rgba_tuple2[:3]
      if rgb_tuple1 not in color_to_index or rgb_tuple2 not in color_to_index:
        print(f"Color not found in global color table: {rgb_tuple}")
        raise ValueError("Color not found in global color table at position: " + str((x, y)))
      x1 = color_to_index[rgb_tuple1]
      x2 = color_to_index[rgb_tuple2]
      b.append(x1 << 4 | x2)
      
  name = "RES_" + (path.split('.')[0]).upper()
  width_entry = f"#define {name}_WIDTH {w}\n"
  height_entry = f"#define {name}_HEIGHT {h}\n"
  oldlen = len(b)
  print("----- orglen of b", oldlen)
  b = rc(b)
  print("----- newlen of b", len(b))
  print("----- compression by ", f"{(oldlen / len(b)):.2f}x" )
  data_entry = f"#define {name}_DATA {','.join([str(i) for i in b])}\n\n"
  return width_entry + height_entry + data_entry

filename = "res.h"
header = ""
header_header = "#ifndef RES_H\n#define RES_H\n\n\n#define RES_H_TILE_AMOUNT 1\n\n"
header_footer = "\n#endif\n"
content = transform_file("all.png")      
      
content = header_header + content + header_footer

with open(here + "/" + filename, "w") as f:
  f.write(content)

file_stats = os.stat(here + "/" + filename)
print(f'----- fsize: {file_stats.st_size / (1024 * 1024)} MB')
