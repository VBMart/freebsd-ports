--- cpp.orig/src/IceSSL/UtilF.h	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceSSL/UtilF.h	2012-03-04 20:14:53.000000000 +0100
@@ -21,13 +21,13 @@
 {
 
 class DHParams;
+IceUtil::Shared* upCast(IceSSL::DHParams*);
 
 }
 
 namespace IceInternal
 {
 
-IceUtil::Shared* upCast(IceSSL::DHParams*);
 
 }
 
