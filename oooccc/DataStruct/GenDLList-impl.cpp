//
//  GenDLList-impl.cpp
//  oooccc
//
//  Created by wangjiawei on 2021/6/1.
//

#include <stdio.h>
#include "GenDLList.cpp"

/*
 当调用指定类型的模板函数，需要添加此类，达到链接的目的
 
 If you compile and (try to) link these two .cpp files, most compilers will generate linker errors. There are two solutions for this. The first solution is to physically move the definition of the template functions into the .h file, even if they are not inline functions. This solution may (or may not!) cause significant code bloat, meaning your executable size may increase dramatically (or, if your compiler is smart enough, may not; try it and see).
 
 解决方案：
 1. 移动cpp中的template到main.cpp
 2. 新建cpp文件重新定义template class
 
 参考链接：https://www.cs.technion.ac.il/users/yechiel/c++-faq/separate-template-class-defn-from-decl.html
 */
template class DoublyLinkedList<int>;
template class DoublyLinkedList<double>;
