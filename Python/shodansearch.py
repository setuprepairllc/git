from shodan import Shodan

api = Shodan('zaRNxhozUAyvFK')

# Search for websites that have been "hacked"
for banner in api.search_cursor('http.title:"hacked by"'):
    print("IP: {}".format(banner['ip_str']))
    print("Banner: {}".format(banner['data']))

# Lookup an IP
ipinfo = api.host('8.8.8.8')
print("IP: {}".format(ipinfo['ip_str']))
print("Banner: {}".format(ipinfo['data']))


