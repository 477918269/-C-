ListNode *detectCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	if (fast == NULL || fast->next == NULL)
		return NULL;

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}
-------------------- -
���ߣ�Linkin_ygw
��Դ��CSDN
ԭ�ģ�https ://blog.csdn.net/linkin_ygw/article/details/54644863 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�