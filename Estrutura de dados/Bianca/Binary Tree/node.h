class Node
{
	public:
		int info;
		Node* left;
		Node* right;
		
		//Construtor
		Node(int n)
		{
			info = n;
			left = right = 0;
		}
};
