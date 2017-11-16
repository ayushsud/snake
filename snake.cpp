#include <iostream>
#include <stdlib.h>
using namespace std;
int f1 = -1, f2 = -1, score = 0, over = 0;
class snake
{
      public:
        int x, y;
        char c = ':';
        snake *next;
};
snake *head = 0;

void StartScreen(char a[41][101], int r, int c)
{
        for (int i = 0; i < r; i++)
        {
                for (int j = 0; j < c; j++)
                        a[i][j] = ' ';
        }
        for (int i = 1; i < c; i++)
        {
                a[0][i] = '_';
                a[40][i] = '_';
        }
        for (int i = 1; i < r; i++)
        {
                a[i][0] = '|';
                a[i][100] = '|';
        }
}

void GenerateSnake(int n)
{
        int j = 22;
        for (int i = 0; i < n; i++, j++)
        {
                snake *n = new snake;
                n->x = 25;
                n->y = j;
                n->next = head;
                head = n;
        }
}

void GenerateFood(int r, int c)
{
        f1 = rand() % r;
        f2 = rand() % c;
        if (head != 0)
        {
        loop:
                for (snake *ptr = head; ptr != 0; ptr = ptr->next)
                {
                        if (f1 == ptr->x && f2 == ptr->y)
                        {
                                f1 = rand() % r;
                                f2 = rand() % c;
                                goto loop;
                        }
                }
        }
}

void UpdateFood(char a[41][101])
{
        a[f1][f2] = '*';
}

void UpdateSnake(char a[41][101])
{
        int f = 0;
        head->c = '#';
        for (snake *ptr = head; ptr != 0; ptr = ptr->next)
                a[ptr->x][ptr->y] = ptr->c;
}
void show(char a[41][101])
{
        cout << "Score=" << score << endl;
        for (int i = 0; i < 41; i++)
        {
                cout << "\t\t\t";
                for (int j = 0; j < 101; j++)
                        cout << a[i][j];
                cout << endl;
        }
}

void up()
{
        int t1 = head->x;
        int t2 = head->y;
        int t3, t4;
        if (head->x - 1 < 1)
                head->x = 39;
        else
                head->x--;
        for (snake *ptr = head->next; ptr != 0; ptr = ptr->next)
        {
                if (head->x == ptr->x && head->y == ptr->y)
                {
                        over = 1;
                        return;
                }
                t3 = ptr->x;
                t4 = ptr->y;
                ptr->x = t1;
                ptr->y = t2;
                t1 = t3;
                t2 = t4;
        }
        if (head->x == f1 && head->y == f2)
        {
                snake *n = new snake;
                n->x = head->x - 1;
                n->y = head->y;
                n->next = head;
                head = n;
                f1 = -1;
                f2 = -1;
                score++;
                GenerateFood(40, 100);
        }
}

void down()
{
        int t1 = head->x;
        int t2 = head->y;
        int t3, t4;
        if (head->x + 1 > 39)
                head->x = 1;
        else
                head->x++;
        for (snake *ptr = head->next; ptr != 0; ptr = ptr->next)
        {
                if (head->x == ptr->x && head->y == ptr->y)
                {
                        over = 1;
                        return;
                }
                t3 = ptr->x;
                t4 = ptr->y;
                ptr->x = t1;
                ptr->y = t2;
                t1 = t3;
                t2 = t4;
        }
        if (head->x == f1 && head->y == f2)
        {
                snake *n = new snake;
                n->x = head->x + 1;
                n->y = head->y;
                n->next = head;
                head = n;
                f1 = -1;
                f2 = -1;
                score++;
                GenerateFood(40, 100);
        }
}

void left()
{
        int t1 = head->x;
        int t2 = head->y;
        int t3, t4;
        head->y--;
        for (snake *ptr = head->next; ptr != 0; ptr = ptr->next)
        {
                if (head->x == ptr->x && head->y == ptr->y)
                {
                        over = 1;
                        return;
                }
                t3 = ptr->x;
                t4 = ptr->y;
                ptr->x = t1;
                ptr->y = t2;
                t1 = t3;
                t2 = t4;
        }
        if (head->x == f1 && head->y == f2)
        {
                snake *n = new snake;
                n->x = head->x;
                n->y = head->y - 1;
                n->next = head;
                head = n;
                f1 = -1;
                f2 = -1;
                score++;
                GenerateFood(40, 100);
        }
}

void right()
{
        int t1 = head->x;
        int t2 = head->y;
        int t3, t4;
        head->y++;
        for (snake *ptr = head->next; ptr != 0; ptr = ptr->next)
        {
                if (head->x == ptr->x && head->y == ptr->y)
                {
                        over = 1;
                        return;
                }
                t3 = ptr->x;
                t4 = ptr->y;
                ptr->x = t1;
                ptr->y = t2;
                t1 = t3;
                t2 = t4;
        }
        if (head->x == f1 && head->y == f2)
        {
                snake *n = new snake;
                n->x = head->x;
                n->y = head->y + 1;
                n->next = head;
                head = n;
                f1 = -1;
                f2 = -1;
                score++;
                GenerateFood(40, 100);
        }
}

void rotate()
{
        node *ptr = head;
        while (ptr != 0)
        {

                int main()
                {
                        int t1, t2, f;
                        char t = ' ';
                        char in;
                        char screen[41][101];
                        StartScreen(screen, 41, 101);
                        GenerateSnake(4);
                        GenerateFood(40, 100);
                        UpdateFood(screen);
                        UpdateSnake(screen);
                        show(screen);
                        while (1)
                        {
                                cin >> in;
                                f = 0;
                                switch (in)
                                {

                                case 'w':
                                        if (t != 's')
                                        {
                                                up();
                                                t = 'w';
                                                f = 1;
                                        }
                                        break;

                                case 'W':
                                        if (t != 's')
                                        {
                                                up();
                                                t = 'w';
                                                f = 1;
                                        }
                                        break;

                                case 'a':
                                        if (t != ' ' && t != 'd')
                                        {
                                                left();
                                                t = 'a';
                                                f = 1;
                                        }
                                        break;

                                case 'A':
                                        if (t != ' ' && t != 'd')
                                        {
                                                left();
                                                t = 'a';
                                                f = 1;
                                        }
                                        break;

                                case 's':
                                        if (t != 'w')
                                        {
                                                down();
                                                t = 's';
                                                f = 1;
                                        }
                                        break;

                                case 'S':
                                        if (t != 'w')
                                        {
                                                down();
                                                t = 's';
                                                f = 1;
                                        }
                                        break;

                                case 'd':
                                        if (t != 'a')
                                        {
                                                right();
                                                t = 'd';
                                                f = 1;
                                        }
                                        break;

                                case 'D':
                                        if (t != 'a')
                                        {
                                                right();
                                                t = 'd';
                                                f = 1;
                                        }
                                        break;

                                case 'r':
                                        rotate();

                                case 'R':
                                        rotate();

                                case 'q':
                                        goto end;

                                case 'Q':
                                        goto end;

                                default:
                                        cout << "Invalid Input.Enter again\n";
                                        break;
                                }
                                if (over)
                                {
                                        cout << "\t\t\t\t\t\t\t\t\tGame Over\n\t\t\t\t\t\t\t\t\tYour Score=" << score << endl;
                                        goto end;
                                }
                                if (f == 1)
                                {
                                        StartScreen(screen, 41, 101);
                                        UpdateSnake(screen);
                                        UpdateFood(screen);
                                        show(screen);
                                }
                        }
                end:
                        return 0;
                }
