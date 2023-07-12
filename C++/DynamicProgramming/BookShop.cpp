#include <iostream>
#include <vector>

int main()
{
    int books, budget;
    std::cin >> books >> budget;

    std::vector<int> priceOfBook(books);
    for (int i = 0; i < books; i++)
        std::cin >> priceOfBook[i];

    std::vector<int> pagesOfBook(books);
    for (int i = 0; i < books; i++)
        std::cin >> pagesOfBook[i];

    std::vector<std::vector<int>> maxPages(books+1, std::vector<int>(budget+1,0));
    for (int i = 0; i < books; i++)
    {
        for (int currBudget = 0; currBudget <= budget; currBudget++)
        {
            maxPages[i+1][currBudget] = maxPages[i][currBudget];
            if (currBudget - priceOfBook[i] >= 0)
                maxPages[i+1][currBudget] = std::max(maxPages[i+1][currBudget], pagesOfBook[i]
                                                 + maxPages[i][currBudget - priceOfBook[i]]);
        }
    }
    std::cout << maxPages[books][budget] << std::endl;
}