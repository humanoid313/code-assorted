import sys
import json
data = {'report':{'settings':{'frequency':500, 'boardtype':'eagle', 'revision':'a2'}, 'complexes':{'xaui':[0,1,2,3], 'sgmii':[4], 'ilk':[]}}}
print "DATA: ", repr(data)
# Encoded data in string data_json
data_json = json.dumps(data, sort_keys=True, indent=2)
#print type(data_json)
print "JSON: ", data_json

# Writing encoded data to a file
json_file = open('tmp.json', 'r+')
json_file.write(data_json)
for line in json_file:
    print line
json_file.close()

# Reading data from file and decoding it
json_file = open('tmp.json', 'r')
data_file = json_file.read()
decoded = json.loads(data_file)
print "Decoded: ", decoded, " Type: ",type(decoded)
print "Encoded: ", json.dumps(data, sort_keys=True)
print "Matches: ", json.dumps(data, sort_keys=True) == decoded
json_file.close()