#include "stdio.h"
#include "string.h"
#include "jni.h"

#undef JNIEXPORT
#define JNIEXPORT __attribute__ ((visibility("default")))

extern "C" JNIEXPORT jstring JNICALL
Java_java_lang_System_getProperty(JNIEnv* e, jstring key)
{
  jstring value = 0;

  jboolean isCopy;
  const char* chars = e->GetStringUTFChars(key, &isCopy);
  if (chars) {
    if (strcmp(chars, "line.separator") == 0) {
      value = e->NewStringUTF("\n");
    }
  }
  e->ReleaseStringUTFChars(key, chars);

  return value;
}
