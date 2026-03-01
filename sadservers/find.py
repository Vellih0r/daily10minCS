def find_max(name):
    maxip = ""
    count = 0
    ip_map = dict()
    with open(name, 'r') as f:
        for ip in f:
            ip = ip.split(' ')[0]
            # if ip not in map
            if ip_map.get(ip) is None:
                ip_map[ip] = 1
            else:
                ip_map[ip] += 1
                if ip == maxip: count += 1
            # if new max ip
            if ip_map[ip] > count:
                maxip = ip
                count = ip_map[ip]
    return maxip

maxip = find_max('a.txt')
print(maxip)
