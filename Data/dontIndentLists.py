import json
import re


class NoIndentList(list):
    pass


# # Function to serialize the dictionary with custom indentation
# def serialize(data, level=0):
#     if isinstance(data, dict):
#         indent = "  " * level
#         items = []
#         for key, value in data.items():
#             if isinstance(value, list):
#                 items.append(
#                     f'{indent}"{key}": {json.dumps(value, separators=(",", ":"))}'
#                 )
#             elif isinstance(value, dict):
#                 items.append(f'{indent}"{key}": {serialize(value, level + 1)}')
#             else:
#                 items.append(f'{indent}"{key}": {json.dumps(value)}')
#         # Join the items with a comma and a newline, but don't add a comma after the last item
#         return "{{\n{}\n{}}}".format(",\n".join(items), indent)
#     elif isinstance(data, NoIndentList):
#         return json.dumps(data, separators=(",", ":"))
#     else:
#         return json.dumps(data)


def serialize(data, level=0):
    indent = "  " * level
    items = []
    for key, value in data.items():
        if isinstance(value, list):
            items.append(
                f'{indent}  "{key}": {json.dumps(value, separators=(",", ":"))}'
            )
        elif isinstance(value, dict):
            items.append(f'{indent}  "{key}": {serialize(value, level + 1)}')
        else:
            items.append(f'{indent}  "{key}": {json.dumps(value)}')
    # Join the items with a comma and a newline, but don't add a comma after the last item
    return "{{\n{}\n{}}}".format(",\n".join(items), indent)


# Load the JSON data
with open("./algoX.json", "r") as f:
    data = json.load(f)

# Wrap the data in NoIndent objects to prevent indentation for 'ratingHistory'
for key, value in data.items():
    value["ratingHistory"] = NoIndentList(value.get("ratingHistory", []))

# Serialize the data
serialized_data = serialize(data)

# Write the serialized data to the file
with open("./algoX.json", "w") as f:
    f.write(serialized_data)
