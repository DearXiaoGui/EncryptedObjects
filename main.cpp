/*
版权声明：

版权所有（C）2023 Xiaogui。保留所有权利。

本软件为开源软件，遵循MIT开源协议。您可以在遵循协议的前提下，自由使用、复制、修改、合并、出版发行、散布、再授权及贩售本软件及其副本。

本软件基于Xor指针加密算法开发，该算法由Xiaogui所开发和拥有。

Xiaogui QQ:1928797351

特此声明。
*/
#include <iostream>
#include "GameWorld.h"
#include "windows.h"
#include "vector"

static GameWorld* _World;

int main()
{
    _World = new GameWorld();
    while (true)
    {
        _World->update();
    }
    return 0;
}