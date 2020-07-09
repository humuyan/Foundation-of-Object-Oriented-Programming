可以使用list，但不可以使用queue，因为Container使用了类模板，但queue没有迭代器且不支持insert操作
可以只使用模板：删去BasicContainer，使用一个模板类实现Container并对vector和multiset进行特化，main函数主要代码修改如下：
template<class A, class C>
void work(Container<A, C> *cont) {
	// 内容不作修改
}
template<class A>
void start(const string &base) {
	if (base == "vector") {
		auto cont = new Container<A, vector<A>>;
		work(cont);
		delete cont;
	} else {
		if (base == "multiset") {
			auto cont = new Container<A, multiset<A>>;
			work(cont);
			delete cont;
		}
	}
}
若要只使用虚函数，可以将特化的模板类改为继承自BasicContainer的4个类，分别对应Container<int, vector<int>>、Container<string, vector<string>>、Container<int, multiset<int>>、Container<string, multiset<string>>，并在main.cpp中对start函数和work函数写4个重载分别实现这4个类的操作。但这样实现繁琐，代码重复度高，同时失去了可拓展性。
