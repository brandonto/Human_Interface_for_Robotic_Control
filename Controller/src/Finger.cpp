//*****************************************************************************
//
// Finger.cpp
//
// Class responsible for modelling a finger on a hand.
//
// Copyright (c) 2015 Brandon To, Minh Mai, and Yuzhou Liu
// This code is licensed under BSD license (see LICENSE.txt for details)
//
// Created:
// December 28, 2015
//
// Modified:
// December 28, 2015
//
//*****************************************************************************
#include "Finger.h"

#include <string>

//*****************************************************************************
//
//! Constructor for Finger. Acquires resources for image.
//!
//! \param None.
//!
//! \return None.
//
//*****************************************************************************
Finger::Finger(FingerType type, SDL_Renderer *renderer)
    : _type(type)
{
    std::string fingerPaths[] = {
        "data/gfx/hand_right_thumb.png",
        "data/gfx/hand_right_index.png",
        "data/gfx/hand_right_middle.png",
        "data/gfx/hand_right_ring.png",
        "data/gfx/hand_right_pinky.png"
    };

    image = std::unique_ptr<Image>(new Image(renderer, fingerPaths[+type]));
}

//*****************************************************************************
//
//! Destructor for Finger.
//!
//! \param None.
//!
//! \return None.
//
//*****************************************************************************
Finger::~Finger()
{

}

//*****************************************************************************
//
//! Gets the image.
//!
//! \param None.
//!
//! \return Returns a reference to the image.
//
//*****************************************************************************
const std::unique_ptr<Image> &Finger::getImage()
{
    return image;
}
