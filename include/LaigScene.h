#ifndef LAIGSCENE_H
#define	LAIGSCENE_H

#include "CGFscene.h"

class LaigScene : public CGFscene
{
private:
	static unsigned int tex_counter;
    bool use_display_lists;
public:
    void enableDisplayLists();
    void disableDisplayLists();
    static void incrementTexCounter();
    
    void init();
    void display();
    void update(long t);
    ~LaigScene();
};

#endif	/* LAIGSCENE_H */