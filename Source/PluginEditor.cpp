/* Copyright (c) 2017-2018 Shane D. Dunne

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "PluginProcessor.h"
#include "PluginEditor.h"

VanillaJuceAudioProcessorEditor::VanillaJuceAudioProcessorEditor (VanillaJuceAudioProcessor& p)
    : AudioProcessorEditor (&p)
    , processor (p)
    , guiTabs(p.getSound())
{
    setSize (600, 300);
    addAndMakeVisible(&guiTabs);
    p.addChangeListener(this);
}

VanillaJuceAudioProcessorEditor::~VanillaJuceAudioProcessorEditor()
{
    processor.removeChangeListener(this);
}

void VanillaJuceAudioProcessorEditor::paint (Graphics& g)
{
    ignoreUnused(g);
}

void VanillaJuceAudioProcessorEditor::resized()
{
    guiTabs.setBounds(0, 0, getWidth(), getHeight());
}

void VanillaJuceAudioProcessorEditor::changeListenerCallback(ChangeBroadcaster* source)
{
    ignoreUnused(source);
    guiTabs.notify();
}