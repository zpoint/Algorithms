#include <stdio.h>
#include <stdlib.h>

void change_beer(int beer_price, int beer_cover_price, int beer_empty_bottle_price, int money, int cover = 0, int empty_bottle = 0, int beer = 0)
{
	int rest_money = 0, rest_cover = 0, rest_empty_bottle = 0;

	rest_money += money % beer_price;
	int exchange_beer = money / beer_price;
	if(exchange_beer > 0)
		printf("用 %d 块钱换了 %d 瓶酒, ", money, exchange_beer);
	rest_cover += exchange_beer;
	rest_empty_bottle += exchange_beer;
	beer += exchange_beer;

	rest_cover += cover % beer_cover_price;
	int exchange_cover = cover / beer_cover_price;
	printf("用 %d 瓶盖换了 %d 瓶酒， ", cover, exchange_cover);
	rest_cover += exchange_cover;
	rest_empty_bottle += exchange_cover;
	beer += exchange_cover;

	rest_empty_bottle += empty_bottle % beer_empty_bottle_price;
	int exchange_empty_bottle = empty_bottle / beer_empty_bottle_price;
	printf("用 %d 空瓶子换了 %d 瓶酒, ", empty_bottle, exchange_empty_bottle);
	rest_cover += exchange_empty_bottle;
	rest_empty_bottle += exchange_empty_bottle;
	beer += exchange_empty_bottle;
	
	printf("\t现在 %d 钱, %d 盖, %d空酒瓶, %d瓶酒\n", rest_money, rest_cover, rest_empty_bottle, beer);

	if (rest_money >= beer_price || rest_cover >= beer_cover_price || rest_empty_bottle >= beer_empty_bottle_price)
		change_beer(beer_price, beer_cover_price, beer_empty_bottle_price, rest_money, rest_cover, rest_empty_bottle, beer);
	else
		printf("\n************************\n*** 总共换了 %d 瓶酒 ***\n************************\n", beer);
	
}

int main(void)
{
	int beer_price;
	int beer_cover_price;
	int beer_empty_bottle_price;
	int money;
	printf("请输入啤酒的价格:(几块一瓶，若2块一瓶输入2): ");
	scanf_s("%d", &beer_price);
	printf("多少个瓶盖换一瓶酒呢? (若4个瓶盖换一瓶酒请输入4): ");
	scanf_s("%d", &beer_cover_price);
	printf("多少个空瓶子换一瓶酒呢? (若2个空瓶换一瓶酒请输入2): ");
	scanf_s("%d", &beer_empty_bottle_price);
	printf("一开始有多少钱呢? (10块钱请输入10): ");
	scanf_s("%d", &money);
	change_beer(beer_price, beer_cover_price, beer_empty_bottle_price, money);
	system("pause");
	return 0;
}