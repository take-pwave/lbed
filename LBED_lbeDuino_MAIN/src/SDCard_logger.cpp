#include "lbed.h"
#include "SD.h"

const int chipSelect = D4;

void setup() {
	/*
	 SD.begin(chipSelect);

	 File dataFile = SD.open("test.txt", FILE_WRITE);

	 // if the file is available, write to it:
	 if (dataFile) {
	 dataFile.println("test");
	 dataFile.close();
	 }
	 */
	Serial pc(D0, D1);
	pc.baud(9600);
	pc.print("\nInitializing SD card...");

	Sd2Card card;
	SdVolume volume;
	SdFile root;
	if (!card.init(SPI_HALF_SPEED, chipSelect)) {
		pc.println("initialization failed. Things to check:");
		pc.println("* is a card is inserted?");
		pc.println("* Is your wiring correct?");
		pc.println(
				"* did you change the chipSelect pin to match your shield or module?");
		return;
	} else {
		pc.println("Wiring is correct and a card is present.");
	}
	// print the type of card
	pc.print("\nCard type: ");
	switch (card.type()) {
	case SD_CARD_TYPE_SD1:
		pc.println("SD1");
		break;
	case SD_CARD_TYPE_SD2:
		pc.println("SD2");
		break;
	case SD_CARD_TYPE_SDHC:
		pc.println("SDHC");
		break;
	default:
		pc.println("Unknown");
	}

	// Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
	if (!volume.init(card)) {
		pc.println(
				"Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
		return;
	}

	// print the type and size of the first FAT-type volume
	uint32_t volumesize;
	pc.print("\nVolume type is FAT");
	pc.print(volume.fatType(), DEC);
	pc.println();

	volumesize = volume.blocksPerCluster(); // clusters are collections of blocks
	volumesize *= volume.clusterCount();       // we'll have a lot of clusters
	volumesize *= 512;                    // SD card blocks are always 512 bytes
	pc.print("Volume size (bytes): ");
	pc.print(volumesize);pc.println();
	pc.print("Volume size (Kbytes): ");
	volumesize /= 1024;
	pc.print(volumesize);pc.println();
	pc.print("Volume size (Mbytes): ");
	volumesize /= 1024;
	pc.print(volumesize);pc.println();

	pc.println("\nFiles found on the card (name, date and size in bytes): ");
	root.openRoot(volume);

	// list all files in the card with date and size
	root.ls(LS_R | LS_DATE | LS_SIZE);

}

void loop() {
}
