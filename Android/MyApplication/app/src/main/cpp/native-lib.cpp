#include <jni.h>
#include <string>
#include <Pds/Ra>


double Norma(double a, double b)
{
    Pds::Matrix A(2);
    A.Set(0,0,a);
    A.Set(1,1,b);
    return A.Norm();
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */,double c)
{
    double a=3;
    std::string hello = "Hello from C++"+std::to_string(Norma(a,c));
    return env->NewStringUTF(hello.c_str());
}
