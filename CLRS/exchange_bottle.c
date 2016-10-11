#include <stdio.h>
#include <stdlib.h>

void change_beer(int beer_price, int beer_cover_price, int beer_empty_bottle_price, int money, int cover = 0, int empty_bottle = 0, int beer = 0)
{
	int rest_money = 0, rest_cover = 0, rest_empty_bottle = 0;

	rest_money += money % beer_price;
	int exchange_beer = money / beer_price;
	if(exchange_beer > 0)
		printf("�� %d ��Ǯ���� %d ƿ��, ", money, exchange_beer);
	rest_cover += exchange_beer;
	rest_empty_bottle += exchange_beer;
	beer += exchange_beer;

	rest_cover += cover % beer_cover_price;
	int exchange_cover = cover / beer_cover_price;
	printf("�� %d ƿ�ǻ��� %d ƿ�ƣ� ", cover, exchange_cover);
	rest_cover += exchange_cover;
	rest_empty_bottle += exchange_cover;
	beer += exchange_cover;

	rest_empty_bottle += empty_bottle % beer_empty_bottle_price;
	int exchange_empty_bottle = empty_bottle / beer_empty_bottle_price;
	printf("�� %d ��ƿ�ӻ��� %d ƿ��, ", empty_bottle, exchange_empty_bottle);
	rest_cover += exchange_empty_bottle;
	rest_empty_bottle += exchange_empty_bottle;
	beer += exchange_empty_bottle;
	
	printf("\t���� %d Ǯ, %d ��, %d�վ�ƿ, %dƿ��\n", rest_money, rest_cover, rest_empty_bottle, beer);

	if (rest_money >= beer_price || rest_cover >= beer_cover_price || rest_empty_bottle >= beer_empty_bottle_price)
		change_beer(beer_price, beer_cover_price, beer_empty_bottle_price, rest_money, rest_cover, rest_empty_bottle, beer);
	else
		printf("\n************************\n*** �ܹ����� %d ƿ�� ***\n************************\n", beer);
	
}

int main(void)
{
	int beer_price;
	int beer_cover_price;
	int beer_empty_bottle_price;
	int money;
	printf("������ơ�Ƶļ۸�:(����һƿ����2��һƿ����2): ");
	scanf_s("%d", &beer_price);
	printf("���ٸ�ƿ�ǻ�һƿ����? (��4��ƿ�ǻ�һƿ��������4): ");
	scanf_s("%d", &beer_cover_price);
	printf("���ٸ���ƿ�ӻ�һƿ����? (��2����ƿ��һƿ��������2): ");
	scanf_s("%d", &beer_empty_bottle_price);
	printf("һ��ʼ�ж���Ǯ��? (10��Ǯ������10): ");
	scanf_s("%d", &money);
	change_beer(beer_price, beer_cover_price, beer_empty_bottle_price, money);
	system("pause");
	return 0;
}