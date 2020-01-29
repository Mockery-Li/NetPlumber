import json

filename = 'rules.json'

m1 = {'method': 'add_source', 'params': {'hs': 'xxxxxxxx', 'ports': [900]}}
m2 = {'method': 'add_source_probe', 'params': {'hs': 'xxxxxxxx', 'mode': 'exist', 'ports': [901], 'test': {'type': 'true'}, 'filter': {'type': 'true'}}}
#m3 = {'method': 'add_link', 'src': 900, 'dst': 1001}
#m4 = {'method': 'add_link', 'src': 2002, 'dst': 901}
data = {'commands': [ m1, m2]}

with open(filename, 'w') as f:
    json.dump(data, f)

outdir = 'mini/'

#topo = {'topology': [{'src': 1002, 'dst': 2001}, {'src': 1001, 'dst': 1002}, {'src': 2001, 'dst': 2002}]}
topo = {'topology': [{'src': 1002, 'dst': 2001}, {'src': 900, 'dst': 1001}, {'src': 2002, 'dst': 901}]}
with open(outdir + "topology.json", "w") as f:
    json.dump(topo, f)

a1 = {'id': 1, 'ports': [1001, 1002], 'rules': [{'action': 'fwd', 'match': '11111111', 'in_ports': [1001], 'out_ports': [1002]}]}
#a1 = {'id': 1, 'ports': [1001, 1002]}
a2 = {'id': 2, 'ports': [2001, 2002], 'rules': [{'action': 'fwd', 'match': 'xxxxxxxx', 'in_ports': [2001], 'out_ports': [2002]}]}
with open(outdir + "a1.tf.json", "w") as f:
    json.dump(a1, f)
with open(outdir + "a2.tf.json", "w") as f:
    json.dump(a2, f)
