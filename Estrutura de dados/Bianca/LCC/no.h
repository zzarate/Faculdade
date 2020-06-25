
class No
{
	public:
		int chave;
		No* prox;
		
		//Construtores
		No()
		{
			prox = 0;
		}
		
		No(int el, No* p = 0)
		{
			chave = el;
			prox = p;
		}
};
