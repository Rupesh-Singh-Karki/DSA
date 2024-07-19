class Solution {
  public:
    Node* createmap(map<Node*,Node*> &nodetoparent,Node* root, int target){
        nodetoparent[root]=NULL;  
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        nodetoparent[root]=NULL;
        
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            
            if(front->data == target){
                res = front;
            }
            
            if(front->left){
                q.push(front->left);
                nodetoparent[front->left]=front;
            }
            if(front->right){
                q.push(front->right);
                nodetoparent[front->right]=front;
            }
        }
        
        return res;
    }
    int burntree(map<Node*,Node*> nodetoparent,Node* root){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        
        visited[root] = true;
        int ans =0;
        
        
        while(!q.empty()){
            
            int size = q.size();
            bool flag =0;
            
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=1;
                    flag =1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=1;
                    flag =1;
                }
                if(nodetoparent[front] && !visited[nodetoparent[front]]){
                    q.push(nodetoparent[front]);
                    visited[nodetoparent[front]]=1;
                    flag =1;
                }
            }
            if(flag==1){
                ans++;
            }
        }
        return ans;
        
    }
    int minTime(Node* root, int target) 
    {
        // 1.create node to parent mapping
        //2.find target
        //3.min time to burn tree
        map<Node*,Node*> nodetoparent;
        Node* res = createmap(nodetoparent,root,target);
        int ans = burntree(nodetoparent,res);
        return ans;
    }
};