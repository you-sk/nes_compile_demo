// --- PPU Register Definitions ---
#define PPU_CTRL    *((unsigned char*)0x2000)
#define PPU_MASK    *((unsigned char*)0x2001)
#define PPU_STATUS  *((unsigned char*)0x2002)
#define PPU_ADDRESS *((unsigned char*)0x2006)
#define PPU_DATA    *((unsigned char*)0x2007)

// --- Palette Data ---
// A simple palette: background, three colors for tiles, then repeated for sprites
const unsigned char palette[]={
  0x0F, 0x00, 0x10, 0x20,  // Background color, and 3 colors for background tiles
  0x00, 0x00, 0x00, 0x00,  // Unused
  0x00, 0x00, 0x00, 0x00,  // Unused
  0x00, 0x00, 0x00, 0x00   // Unused
};

// --- "HELLO" Text ---
const char text[] = "HELLO WORLD";


// --- Main Program ---
void main(void) {
  unsigned char i;

  // --- Initialization ---

  // Wait for the PPU to be ready (VBlank)
  while ((PPU_STATUS & 0x80) == 0);

  // Turn off the screen before changing PPU memory
  PPU_MASK = 0x00;
  PPU_CTRL = 0x00;

  // Load the palette data into PPU memory ($3F00)
  PPU_ADDRESS = 0x3F;
  PPU_ADDRESS = 0x00;
  for(i = 0; i < sizeof(palette); ++i) {
    PPU_DATA = palette[i];
  }

  // Write the text data to the nametable ($2007)
  PPU_ADDRESS = 0x20;
  PPU_ADDRESS = 0x40; // Address to write "HELLO WORLD"
  for(i = 0; text[i] != '\0'; ++i) {
    PPU_DATA = text[i];
  }

  // Turn the screen back on (enable background rendering)
  PPU_CTRL = 0x80; // Enable NMI for VBlank
  PPU_MASK = 0x0E; // Enable background rendering

  // --- Infinite Loop ---
  // The program now runs forever doing nothing
  while(1);
}