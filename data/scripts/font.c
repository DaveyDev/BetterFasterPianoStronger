// Custom function to draw text with adjusted position. XD i really wanted to make this font work //next update make it work properly
void DrawTextExAdjusted(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint) {
    Vector2 adjustedPosition = position;

    for (int i = 0; text[i] != '\0'; i++) {
        // Adjust position for 'E' character
        if (text[i] == 'A') {
        //adjustedPosition.x -= 2;  // Adjust this value as needed
        }
        if (text[i] == 'A') {
            //adjustedPosition.x += 2;  // Adjust this value as needed
        }
        if (text[i] == 'B') {
            adjustedPosition.x += 15;  // Adjust this value as needed
        }
        if (text[i] == 'C') {
            adjustedPosition.x += 15;  // Adjust this value as needed
        }

        // Draw each character
        DrawTextEx(font, TextFormat("%c", text[i]), adjustedPosition, fontSize, spacing, tint);

        // Update position for the next character
        adjustedPosition.x += MeasureTextEx(font, TextFormat("%c", text[i]), fontSize, spacing).x;

        // Reset the position adjustment for next characters
        if (text[i] == 'E') {
            adjustedPosition.x -= 15;
        }
        if (text[i] == 'A') {
            adjustedPosition.x += 2;
        }
        if (text[i] == 'B') {
            adjustedPosition.x -= 15;
        }
        if (text[i] == 'C') {
        adjustedPosition.x += 2;  // Adjust this value as needed
        }
        if (text[i] == 'L') {
        adjustedPosition.x += 2;  // Adjust this value as needed
        }
        
    }
}