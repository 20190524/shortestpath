//Greedy Best-First Search
//目的地固定为Bucharest，出发地由用户输入:source

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_V 1024

struct edge//结构体用于存放城市之间的距离
{
    int to, cost;//to是目的城市，cost是花销
    edge(){}
    edge(int to, int cost)
    {
        this->to = to;
        this->cost = cost;
    }
};

int V, E;
vector<edge> G[MAX_V]; //城市之间的路，最大距离，这个应该是数组类的vector
int Huristic[MAX_V]={0}; //城市之间估计的直线距离
char vertex[MAX_V][30]={0}; //城市名称

void init_test(){
    V = 20;//城市个数
    E = 46;//？
    Huristic[0]=366;
    Huristic[1]=0;
    Huristic[2]=160;
    Huristic[3]=242;
    Huristic[4]=161;
    Huristic[5]=176;
    Huristic[6]=77;
    Huristic[7]=151;
    Huristic[8]=226;
    Huristic[9]=244;
    Huristic[10]=241;
    Huristic[11]=234;
    Huristic[12]=380;
    Huristic[13]=10;
    Huristic[14]=193;
    Huristic[15]=253;
    Huristic[16]=329;
    Huristic[17]=80;
    Huristic[18]=199;
    Huristic[19]=374;
    strcpy(vertex[0],"Arad");
    strcpy(vertex[1],"Bucharest");
    strcpy(vertex[2],"Craiova");
    strcpy(vertex[3],"Dobreta");
    strcpy(vertex[4],"Eforie");
    strcpy(vertex[5],"Fagaras");
    strcpy(vertex[6],"Giurgiu");
    strcpy(vertex[7],"Hirsova");
    strcpy(vertex[8],"Iasi");
    strcpy(vertex[9],"Lugoj");
    strcpy(vertex[10],"Mehadia");
    strcpy(vertex[11],"Neamt");
    strcpy(vertex[12],"Oradea");
    strcpy(vertex[13],"Pitesti");
    strcpy(vertex[14],"Rimnicu Vilcea");
    strcpy(vertex[15],"Sibiu");
    strcpy(vertex[16],"Timisoara");
    strcpy(vertex[17],"Urziceni");
    strcpy(vertex[18],"Vaslui");
    strcpy(vertex[19],"Zerind");
    G[0].push_back(edge(19, 75));
    G[19].push_back(edge(0, 75));
    G[0].push_back(edge(15, 140));
    G[15].push_back(edge(0, 140));
    G[0].push_back(edge(16, 118));
    G[16].push_back(edge(0, 118));
    G[1].push_back(edge(5, 211));
    G[5].push_back(edge(1, 211));
    G[1].push_back(edge(13, 101));
    G[13].push_back(edge(1, 101));
    G[1].push_back(edge(6, 90));
    G[6].push_back(edge(1, 90));
    G[1].push_back(edge(17, 85));
    G[17].push_back(edge(1, 85));
    G[2].push_back(edge(3, 120));
    G[3].push_back(edge(2, 120));
    G[2].push_back(edge(14, 146));
    G[14].push_back(edge(2, 145));
    G[2].push_back(edge(13, 138));
    G[13].push_back(edge(2, 138));
    G[3].push_back(edge(10, 75));
    G[10].push_back(edge(3, 75));
    G[4].push_back(edge(7, 86));
    G[7].push_back(edge(4, 86));
    G[5].push_back(edge(15, 99));
    G[15].push_back(edge(5, 99));
    G[7].push_back(edge(17, 98));
    G[17].push_back(edge(7, 98));
    G[8].push_back(edge(11, 87));
    G[11].push_back(edge(8, 87));
    G[8].push_back(edge(18, 92));
    G[18].push_back(edge(8, 92));
    G[9].push_back(edge(10, 70));
    G[10].push_back(edge(9, 70));
    G[9].push_back(edge(16, 111));
    G[16].push_back(edge(9, 111));
    G[12].push_back(edge(19, 71));
    G[19].push_back(edge(12, 71));
    G[12].push_back(edge(15, 151));
    G[15].push_back(edge(12, 151));
    G[13].push_back(edge(14, 97));
    G[14].push_back(edge(13, 97));
    G[14].push_back(edge(15, 80));
    G[15].push_back(edge(14, 80));
    G[17].push_back(edge(18, 142));
    G[18].push_back(edge(17, 142));
}

class Node {
public:
    vector<int> path;
    Node(int v ) {
//        cout<<"node      "<<v<<endl;
    this ->v= v;
    h=Huristic[v];
//    path.push_back(this->v);
    }
//    Node(const Node&n)
//    {
//        cout<<"copying"<<endl;
//        this->v=n.v;
//        h=n.h;
//        int i=n.path.size();
//        for(int j=0;j<i;j++){
//            this->path.push_back(n.path.at(j));
//        }
//    }
  ~Node() {}
  int getV() const { return v; }//城市个数
  int getH() const { return h; }//距离
  int getPre() const { return pre; }//
  void setH(int h) { this->h = h; }
  void setPre(int pre) {this->pre = pre; }
private:
  int v;
  int h;
  int pre;
};

bool operator < (const Node& n1, const Node& n2) //重写优先级队列排序规则
{
  return n1.getH() > n2.getH();
}




void ShowPath(const vector<int>& path)//与v相关
{
//    int l=0;
    for (vector<int>::const_iterator iter = path.begin(); iter != path.end(); iter++)
    {
//        cout<<"iternum"<<l<<endl;
        cout << vertex[*iter] <<"->";
//        l++;
    }
    return ;
}


//需要补充
void Best_First(int source)
{
    priority_queue<Node>  Que;//优先级队列
    Node node(source);//出发地
//    node.path.push_back(source);
    Que.push(node);
    while (!Que.empty())
    {
        cout<<"notempty"<<endl;
        //弹出h值最小的节点，也就是离目的地最近的一个节点
        Node s=Que.top();
//        s.path.push_back(s.getV());
        cout<<"top'snum  "<<s.getV()<<endl;
        Que.pop();
//        cout<<"minGetV"<<min.getV()<<endl;
//        Que.pop();
        //判断是否到达目的地，目的地序号1
        if(s.getH()==0){
            cout<<"shortest"<<endl;
            s.path.push_back(s.getV());
            ShowPath(s.path);
            break;
        }
        else{
            Node min=G[s.getV()].at(0).to;
            for(unsigned i=0;i<G[s.getV()].size();i++){
                Node comp=G[s.getV()].at(i).to;//去的城市
                if(comp.getV()!=s.getPre())
                {
                    if(!(comp<min)){
                        min=comp;
//                        min.path.push_back(min.getV());
                    }
                }
    //            Que.pop();
            }
            min.setPre(s.getV());
            for(int i=0;i<s.path.size();i++){
                min.path.push_back(s.path.at(i));
            }
//            min.path.push_back(min.getV());
            min.path.push_back(min.getPre());
            cout<<"mingetV      "<<min.getV()<<endl;
            Que.push(min);
        }
        //若为目的地，则输出路径
        //否则，展开下一层节点，并存入优先级队列
//        int p=near.getPre();
//        Node next=near(p);
//        Que.push(next);
    }
    return ;
}


int main(int argc, char *argv[])
{
    init_test();//输入所有的城市及数据
    cout<<"Source:";
    int source;//出发点城市
    cin>>source;
    Best_First(source);
    return 0;
}
