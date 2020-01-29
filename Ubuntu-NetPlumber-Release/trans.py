import json
dir = "tfs/"
outdir = "temp/"
with open(dir + "port_map.json") as f:
    port_map = json.load(f)

i = 1

for key in port_map:
    print(key)
    fname = dir + key + ".tf.json"
    print(fname)
    with open(fname) as f:
        data = json.load(f)
        data["id"] = i
        i = i+1
        data["ports"] = list(port_map[key].values())
        with open(outdir + key + ".tf.json", "w") as of:
            json.dump(data, of)

