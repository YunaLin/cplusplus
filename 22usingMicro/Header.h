//
//  Header.h
//  C++
//
//  Created by 李天培 on 16/3/5.
//  Copyright © 2016年 lee. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>

#define MAX 100
#define MIN -100

#define max(a, b) (a) > (b) ? (a) : (b)
#define square(a) ((a)*(a))
#define e(a, b) (a##e##b)

#define mstr(expr) str(expr)
#define str(num) #num

#define WARN_IF(EXP) \
if (EXP) {\
    std::cout << "Warning: " << #EXP  << "\n";\
}

#endif /* Header_h */
