void CreateGraph(AdjMatrix *G) //ͼ�����ɺ���
{
	int n, e, vi, vj, w, i, j;
	printf("������ͼ�Ķ������ͱ������Կո�ָ�����");
	scanf("%d%d", &n, &e);
	G->numV = n; G->numE = e;
	for (i = 0; i<n; i++) //ͼ�ĳ�ʼ��
	for (j = 0; j<n; j++)
	{
		if (i == j)
			G->Edge[i][j] = 0;
		else
			G->Edge[i][j] = 32767;
	}
	for (i = 0; i<G->numV; i++) //���������������
	{
		printf("�������%d���������Ϣ:", i + 1);
		scanf("%d", &G->Vertices[i]);
	}
	printf("\n");

	for (i = 0; i<G->numE; i++)
	{
		printf("������ߵ���Ϣi,j,w(�Կո�ָ�):");
		scanf("%d%d%d", &vi, &vj, &w);
		//��Ϊ����Ȩֵ��ͼ����w����1
		//��Ϊ��Ȩֵ��ͼ����w�����ӦȨֵ

		G->Edge[vi - 1][vj - 1] = w;//��
		G->Edge[vj - 1][vi - 1] = w;//��
		//����ͼ���жԳ��ԵĹ��ɣ�ͨ���٢�ʵ��
		//����ͼ���߱������ʣ�����ֻ��Ҫ��
	}
}
