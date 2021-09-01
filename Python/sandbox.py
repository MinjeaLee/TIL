import base64  

id = "admin"
pw = "nimda"

for i in range(0, 20):
    id = base64.b64encode(id.encode('ascii'))    
    pw = base64.b64encode(pw.encode('ascii'))    
    id = id.decode("ascii")
    pw = pw.decode("ascii")


print("id = {}".format(id))
print("pw = {}".format(pw))






