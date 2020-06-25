class BTreeNode
{
	private:
		int n;//Número de chaves atualmente armazenadas
		bool leaf; //É folha?
		int* key;//chaves
		BTreeNode** c;//Ponteiros para os filhos
		BTreeNode* parent;//Pai
		
	public:
		BTreeNode(int);
};
