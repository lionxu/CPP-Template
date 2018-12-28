void call1();
void call();

/*
 * 在链接阶段,编译器将随机选择一个目标文件的静态成员变量,
 * 让the_class<int>类来共享这个静态成员变量.
 */
int main() {
	call1();
	call();
	return 0;
}