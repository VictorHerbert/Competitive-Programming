

template <typename T>
struct Node{
    T id;

    Node* father;
    Node* left; //menor
    Node* right; //maior

    Node(const T& _id, Node* _father, Node* _left = NULL, Node* _right = NULL):
        father(_father),
        id(_id),
        left(_left),
        right(_right){};

};

template <typename T>
struct BST {
    Node<T> root;

    BST(const T& id):
        root(Node<T> (id,NULL)){};

    ~BST(){ this->clear(); }

    void clear(){
        clearSubThree(&root);
    }

    void clearSubThree(Node<T>* n){
        if(n->left != NULL)
            clearSubThree(n->left);
        if(n->right != NULL)
            clearSubThree(n->right);

        cout << n->id << "|";

        delete n;
    }

    void insert(const T& id){
        _insert(id,&root);
    }

    void _insert(const T& id, Node<T>* pos){
        if(id <= pos->id){
            if(pos->left == NULL)
                pos->left = new Node<T> (id,pos);
            else
                _insert(id,pos->left);
        }
        if(id > pos->id){
            if(pos->right == NULL)
                pos->right = new Node<T> (id,pos);
            else
                _insert(id,pos->right);
        }
    }

    void infix (){
        vector<Node<T>*> order;
        _infix(&root,order);
        cout << order[0]->id;
        for(int i = 1; i < order.size(); i++){
            cout << " " << order[i]->id;
        }
        cout << "\n";
    }

    void _infix(Node<T>* n, vector<Node<T>*>& ord){

        if(n->left != NULL)
            _infix(n->left,ord);

        ord.push_back(n);

        if(n->right != NULL)
            _infix(n->right,ord);
    }

    void prefix (){
        vector<Node<T>*> order;
        _prefix(&root,order);
        cout << order[0]->id;
        for(int i = 1; i < order.size(); i++){
            cout << " " << order[i]->id;
        }
        cout << "\n";
    }

    void _prefix(Node<T>* n, vector<Node<T>*>& ord){

        ord.push_back(n);

        if(n->left != NULL)
            _prefix(n->left,ord);

        if(n->right != NULL)
            _prefix(n->right,ord);
    }

    void posfix (){
        vector<Node<T>*> order;
        _posfix(&root,order);
        cout << order[0]->id;
        for(int i = 1; i < order.size(); i++){
            cout << " " << order[i]->id;
        }
        cout << "\n";
    }

    void _posfix(Node<T>* n, vector<Node<T>*>& ord){

        if(n->left != NULL)
            _posfix(n->left,ord);

        if(n->right != NULL)
            _posfix(n->right,ord);

        ord.push_back(n);
    }

    void print(Node<T>* n, int lv = 0){
        for(int i = 0; i < lv; i++){
            cout << "   ";
        }

        cout << n->id << "\n";

        if(n->right != NULL)
            print(n->right,lv+1);
        if(n->left != NULL)
            print(n->left, lv+1);

    }

    Node<T>* search(const T& id){
        return _search(id,&this->root);
    }

    Node<T>* _search(const T& id, Node<T>* pos){
        if(id < pos->id){
            if(pos->left == NULL)
                return NULL;
            else
                return _search(id,pos->left);
        }
        if(id > pos->id){
            if(pos->right == NULL)
                return NULL;
            else
                return _search(id,pos->right);
        }
        if(id == pos->id)
            return pos;
    }

    bool remove(const T& id){
        Node<T>* pos = this->search(id);
        if(pos == NULL)
            return false;
        else{
            if(pos->right == NULL && pos->right == NULL){
                if(pos->father->left == pos)
                    pos->father->left = NULL;
                else
                    pos->father->right = NULL;

                delete pos;
            }
            if(pos->left == NULL && pos->right != NULL){
                if(pos->father->left == pos)
                    pos->father->left = pos->right;
                else
                    pos->father->right = pos->right;

                delete pos;
            }
            if(pos->left != NULL && pos->right == NULL){
                if(pos->father->left == pos)
                    pos->father->left = pos->left;
                else
                    pos->father->right = pos->left;

                delete pos;
            }
            if(pos->left != NULL && pos->right != NULL){
                Node<T>* m = pos->left;

                while(m->right != NULL){
                    m = m->right;
                }
                if(m->father->left == m){
                    if(m->left != NULL){
                        m->father->left = m->left;
                        m->left->father = m->father->left;
                    }
                    else
                        m->father->left = NULL;
                }
                else{
                    if(m->left != NULL){
                        m->father->right = m->left;
                        m->left->father = m->father->right;
                    }
                    else
                        m->father->right = NULL;
                }
                pos->id = m->id;
            }
        }

        return true;

    }

};

template <typename T>
ostream& operator << (ostream& os, BST<T>& t)  {
    t.print(&t.root);

    return os << "\n";
}

