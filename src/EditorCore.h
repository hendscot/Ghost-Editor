#ifndef EDITORCORE_H
#define EDITORCORE_H
#include "Document.h"
#include "LineManager.h"
namespace Comet {
    class EditorCore {
    public:
        EditorCore;
        ~EditorCore;
    
    protected:
        bool         e_shouldClose;                    // State variable that alerts system loop to end


        void         Init              ();             // Initialize ncurses and private members
        void         Poll              ();
        void         Load              (const char*);  // Call Document class LoadDocument method which loads file state into a doc buffer
        void         Save              ();             // Save current file state
        void         Delete            (int, int);     // Interface for LineMan Deletechar method (deletes specified index at current line)
        
    // BEGIN PRIVATE DATA
    private:
        // PRIVATE MEMBERS
        char*        e_path;                           // Maintains string of filepath
        int          e_key;                            // Stores value of key pressed by user
        int          e_currLine;                       // Current column (index) to be passed to ncurses and to manipulate files
        int          e_currIndex;                      // Current row (line) to be passed to ncurses and to manipulate files
        LineMan*     e_man;                            // LineMan object which contains and controls lines
        Document*    e_doc;                            // Document object for loading and saving files to be manipulated

        // PRIVATE METHODS
        void         Display           ();             // Call LineMan class Display method, loads state of file into ncurses window after change
        void         HandleInput       ();
    };
}
#endif // EDITORCORE_H