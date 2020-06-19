#include "syscan.h"

int devClassSize = 21;

const char *devClass[21][3] = {
  { 0x00, "Device", "Use class information in the Interface Descriptors" },
  { 0x01, "Interface", "Audio" },
  { 0x02, "Both", "Communications and CDC Control" },
  { 0x03, "Interface", "HID (Human Interface Device)" },
  { 0x05, "Interface", "Physical" },
  { 0x06, "Interface", "Image" },
  { 0x07, "Interface", "Printer" },
  { 0x08, "Interface", "Mass Storage" },
  { 0x09, "Device", "Hub" },
  { 0x0A, "Interface", "CDC-Data" },
  { 0x0B, "Interface", "Smart Card" },
  { 0x0D, "Interface", "Content Security" },
  { 0x0E, "Interface", "Video" },
  { 0x0F, "Interface", "Personal Healthcare" },
  { 0x10, "Interface", "Audio/Video Devices" },
  { 0x11, "Device", "Billboard Device Class" },
  { 0x12, "Interface", "USB Type-C Bridge Class" },
  { 0xDC, "Both", "Diagnostic Device" },
  { 0xE0, "Interface", "Wireless Controller" },
  { 0xEF, "Both", "Miscellaneous" },
  { 0xFE, "Interface", "Application Specific" },
  { 0xFF, "Both", "Vendor Specific" },
};

char *getUSBIDs() {
  char buf[700000]; // 700ko
  char *p = buf;
  readFile("/var/lib/usbutils/usb.ids", buf);
  return p;
}

char **getVendorAndProduct(char *buf, char *vendorID, char *productID) {
  printf("=== %s - %s", vendorID, productID);
  /*char newline[5] = "\n";

  strcat(newline, vendorID);

  printf("-%s-\n", newline);
  char *res;
  //if ((res = strstr(buf, newline)) == NULL)
  //  printf("NULL");
  printf("%s", strstr(buf, newline));
  printf("[%s]", res);
  const char *delim = "\n";
  char *strToken = strtok(res, delim);
  printf("<%s>", strToken);

  char **arr = malloc(100);
  arr[0] = malloc(100);
  arr[1] = malloc(100);


  strToken += 6;
  arr[0] = malloc(sizeof(char) * strlen(strToken));
  strcpy(arr[0], strToken);

  while (strstr(strToken, productID) == 0)
    strToken = strtok(NULL, delim);

  printf("<%s>", strToken);

  /*strToken += 7;
  arr[1] = malloc(sizeof(char) * strlen(strToken));
  strcpy(arr[1], strToken);*/
  //return arr;*/
}

char *getClassUsage(int base) {
  for (int i = 0; i < devClassSize; i++)
    if (base == devClass[i][0])
      return devClass[i][1];
  return "";
}

char *getClassDescription(int base) {
  for (int i = 0; i < devClassSize; i++)
    if (base == devClass[i][0])
      return devClass[i][2];
  return "";
}

void lsusb() {
  struct usb_bus *bus;
  struct usb_device *dev;
  char *usbid = getUSBIDs();

  usb_init();
  usb_find_busses();
  usb_find_devices();

  for (bus = usb_busses; bus; bus = bus->next)
    for (dev = bus->devices; dev; dev = dev->next) {
      char product[19];
      snprintf(product, 10, "%04x", dev->descriptor.idProduct);
      snprintf(product, 5, "%04x", dev->descriptor.idVendor);
      //printf("%s\n", product);
      //snprintf(vendor, 5, "%04x", dev->descriptor.idVendor);
      //printf("%s - %s | %x %x\n", vendor, product, dev->descriptor.idVendor, dev->descriptor.idProduct);
      //getVendorAndProduct(usbid, vendor, product);
      //printf("%s : %s\n", info[0], info[1]);
      printf("Bus %s"
      " Device %s:"
      " ID %04x:%04x "
      " USB: v%2x.%01x"
      " Class: %x %s %s"
      " Subclass: %x"
      " Protocol: %x\n",
      bus->dirname,
      dev->filename,
      dev->descriptor.idVendor,
      dev->descriptor.idProduct,
      //info[0],
      //info[1],
      dev->descriptor.bcdUSB >> 8, dev->descriptor.bcdUSB & 0xff,
      dev->descriptor.bDeviceClass,
      getClassUsage(dev->descriptor.bDeviceClass),
      getClassDescription(dev->descriptor.bDeviceClass),
      dev->descriptor.bDeviceSubClass,
      dev->descriptor.bDeviceProtocol);
    }
}
