#include <filesystem>

int main()
{
	std::filesystem::path cwd = std::filesystem::current_path();
	(void)cwd;
}
