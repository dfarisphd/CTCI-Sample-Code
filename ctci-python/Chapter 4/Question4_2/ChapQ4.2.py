#Given a directed graph, design an algorithm to find out whether there is a route
#between two nodes.

class DirectedGraph:
    def __init__(self,content):
        self.content = content
        self.neighbours = []

#"dynamic programming" used here, i.e. recursion plus caching
#"cache" is our dict of visited nodes
#"cache2" is our dict of routes (i.e. 3,5) that have already been checked.
def is_route_between(node1,node2,cache={},cache2={}):    
    if node1==node2:
        return True
    if (str(hash(node1)) + "," + str(hash(node2))) in cache2:
        return cache2[(str(hash(node1)) + "," + str(hash(node2)))]    
    nodefound=False
    for neighbour in node1.neighbours:
        if neighbour in cache:
            #dont visit, we've checked this already in our route search
            continue
        cache[neighbour]=True
        nodefound=is_route_between(neighbour,node2,cache,cache2)
        if nodefound:
            break
    cache2[(str(hash(node1)) + "," + str(hash(node2)))]=nodefound
    return nodefound

#testing

n1 = DirectedGraph(1)
n2 = DirectedGraph(2)
n3 = DirectedGraph(3)
n4 = DirectedGraph(4)
n5 = DirectedGraph(5)
n6 = DirectedGraph(6)

n1.neighbours.append(n2)
n2.neighbours.append(n3)
n2.neighbours.append(n4)
n4.neighbours.append(n5)
n4.neighbours.append(n1)

if is_route_between(n1,n5):
    print "Test 1 passed"

if not is_route_between(n5,n1):
    print "Test 2 passed"

if not is_route_between(n1,n6):
    print "Test 3 passed"
