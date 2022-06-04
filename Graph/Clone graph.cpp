// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

// Detailed Explanation with map

class Solution {
public:
  Node* cloneGraph(Node* node) {
      if(!node)return NULL;
      unordered_map<Node*,Node*> map;

 // create a new node with the nodes value
       Node* copy=new Node(node->val);   
       map[node]=copy; 

   // store it in the map so it will help get access to that element in o(1) time
       queue<Node*> q;
       q.push(node);
       while(!q.empty()){
           Node* t=q.front();
           q.pop();
           for(Node* x:t->neighbors)    

 // explore all of its neighbors to make copies of edges and its adj nodes
           {
               if(!map.count(x))   // to make sure we dont visit node multiple times
               {
                   map[x]=new Node(x->val);   //We create the new nodes
                   q.push(x);
               }
               map[t]->neighbors.push_back(map[x]);   //This the creation of edges
           }  
       }
       return copy;
  }
};
