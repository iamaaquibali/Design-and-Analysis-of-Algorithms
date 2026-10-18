#include <stdio.h>

int main()
{
    int N, W;
    int value[1000], weight[1000];
    int dp[1001] = {0};

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &value[i]);

    for (int i = 0; i < N; i++)
        scanf("%d", &weight[i]);

    scanf("%d", &W);

    for (int i = 0; i < N; i++)
    {
        for (int w = W; w >= weight[i]; w--)
        {
            int include = value[i] + dp[w - weight[i]];

            if (include > dp[w])
                dp[w] = include;
        }
    }

    printf("%d\n", dp[W]);

    return 0;
}
