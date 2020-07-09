1. AbstractWrapper构造函数的中只会调用基类的type()，需将type作为参数传入
2. 编译器自动合成的析构函数非虚，基类需要手动指定一个虚的析构函数
3. 默认为private继承无法访问基类函数，须改为public继承
4. IntegerWrapper成员含有指针，实现析构函数释放指针空间更安全
5. StringWrapper的ptr为char数组，须使用delete[]释放空间
6. StringWrapper中length()函数被重写隐藏，须使用using使ChineseStringWrapper类中也可调用length()
