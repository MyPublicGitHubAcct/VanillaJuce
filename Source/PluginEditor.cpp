#include "PluginProcessor.h"
#include "PluginEditor.h"

VanillaJuceAudioProcessorEditor::VanillaJuceAudioProcessorEditor (VanillaJuceAudioProcessor& p)
    : AudioProcessorEditor (&p)
    , processor (p)
    , guiTabs(p.getSound(), p.getDspClient())
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