import os

here = os.path.dirname(os.path.abspath(__file__))
os.chdir(here)

BMP_HEADER_SIZE = 70
BMP_HEADER_WIDTH_BEGIN = 18
BMP_HEADER_HEIGHT_BEGIN = 22
BMP_HEADER_DIM_FIELD_LEN = 4

def transform_file(path):
  with open(here + "/files/" + path, "rb") as f:
    data = f.read()
    print(data[BMP_HEADER_WIDTH_BEGIN])
    width = int.from_bytes(data[BMP_HEADER_WIDTH_BEGIN:BMP_HEADER_WIDTH_BEGIN + BMP_HEADER_DIM_FIELD_LEN], byteorder='little')
    height = int.from_bytes(data[BMP_HEADER_HEIGHT_BEGIN:BMP_HEADER_HEIGHT_BEGIN + BMP_HEADER_DIM_FIELD_LEN], byteorder='little')
    content = "".join(f'0x{b:02x},' for b in data[BMP_HEADER_SIZE:])
    content = content[:-1]
    qualified_name = ("res_" + path.split(".")[0].replace("/", "_")).upper()
    toprint = f"#define {qualified_name}_W {width}\n"
    toprint += f"#define {qualified_name}_H {height}\n"
    toprint += f"#define {qualified_name} {content}\n\n"
    return toprint

filename = "res.h"

header = ""

header_header = "#ifndef RES_H\n#define RES_H\n\n\n"
header_footer = "\n#endif\n"
content = ""

# for every file found in this directory recursively
for root, dirs, files in os.walk(here + "/files"):
  for file in files:
    content += transform_file(file)

content = header_header + content + header_footer

# write it to the header file res.h
with open(here + "/" + filename, "w") as f:
  f.write(content)

print(content)
