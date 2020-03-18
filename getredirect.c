// Adopted from https://curl.haxx.se/libcurl/c/getredirect.html
// Adopted from https://curl.haxx.se/libcurl/c/postit2.html
// Tom Lou (louyu27@cs.washington.edu)
#include <stdio.h>
#include <curl/curl.h>

char *target = "127.0.0.1:5000/predict";
char *file_name = "ILSVRC2012_val_00000003.jpeg";

size_t handle_data(char *data, size_t n, size_t l, void *userp) {
  for (int i = 0; i < n*l; i++) {
    putchar(data[i]);
  }
  return n*l;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  char *location;
  long response_code;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, target);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_data);

    curl_mime *form = curl_mime_init(curl);

    curl_mimepart *field = curl_mime_addpart(form);;

    curl_mime_name(field, "image");
    curl_mime_filedata(field, file_name);
    
    curl_easy_setopt(curl, CURLOPT_MIMEPOST, form);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    else {
      res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      if((res == CURLE_OK) &&
         ((response_code / 100) == 4)) {
        /* a redirect implies a 3xx response code */
        fprintf(stderr, "Connection error");
      }
    }

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}
