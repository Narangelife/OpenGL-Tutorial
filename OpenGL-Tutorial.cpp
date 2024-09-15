//========================================================================================
/**
 * @file OpenGL-Tutorial.cpp
 * @brief https://www.opengl-tutorial.org/jp/ のチュートリアルをするよ
 * @author Narange
 * @copyright ©Narange
 */
//========================================================================================
#include "OpenGL-Tutorial.h"

// GL
#include <GL/glew.h>
#include "GLFW/glfw3.h"

using namespace std;

int main()
{
	cout << "Hello OpenGL-Tutorial." << endl;

	if (!glfwInit())
	{
		cout << "GLFW initialize failed." << endl;
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);                               // 4x アンチエイリアス
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 // OpenGL3.3を使います。
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // MacOS用：必ずしも必要ではありません。
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 古いOpenGLは使いません。

	// Window Context
	GLFWwindow* p_window = glfwCreateWindow(1024, 768, "Tutorial 01", nullptr, nullptr);
	if (p_window == nullptr) {
		cout << "GLFW initialize failed." << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(p_window); // GLFWを初期化する

	glewExperimental = true; // コアプロファイルで必要となります。
	if (glewInit() != GLEW_OK) {
		cout << "GLEW initialize failed." << endl;
		glfwTerminate();
		return -1;
	}

	// 下でエスケープキーが押されるのを捉えるのを保証します。
	glfwSetInputMode(p_window, GLFW_STICKY_KEYS, GL_TRUE);

	do {
		// 何も描きません。チュートリアル2で会いましょう！

		// バッファをスワップする。
		glfwSwapBuffers(p_window);
		glfwPollEvents();

	} // ESCキーが押されたかウィンドウが閉じたかをチェックする。
	while (glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(p_window) == 0);

	return 0;
}
