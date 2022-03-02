from urllib import parse

url = parse.urlparse('https://webhacking.kr?id=admin')

query = parse.parse_qs(url.query)
result = parse.urlencode(query, doseq=True)

print(query)
print(result)