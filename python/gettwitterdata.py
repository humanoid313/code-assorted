import twitter
import networkx as nx
import matplotlib.pyplot as plt

api = twitter.Api(consumer_key='cons_key',\
				  consumer_secret='cons_secret',\
				  access_token_key='a_t_key',\
				  access_token_secret='a_t_secret'\
 				 )
G = nx.MultiDiGraph()
src = u'humanoid313'
#statuses = api.GetUserTimeline(src)
friends = api.GetFriends()

users = list()
users.append(src)
flist = [f.GetScreenName() for f in friends]
users.extend(flist)

for u in users:
    if len(users) < 100:
        statuses = api.GetUserTimeline(u)
        for status in statuses:
            recipt =  status.GetInReplyToScreenName()
            if recipt is not None:
                try:
                    users.index(recipt)
                except ValueError:
                    users.append(recipt)
                G.add_edge(u, recipt, message=status)
            else:
                #G.add_edge(u, u"None", message=status)
                pass
    else:
        break
try: 
        pos=nx.spring_layout(G,iterations=5)
        nx.draw(G,pos,node_size=0,alpha=0.5,edge_color='r',font_size=12)
        plt.show()
except: 
        pass
