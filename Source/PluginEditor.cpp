/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WillHPFAudioProcessorEditor::WillHPFAudioProcessorEditor (WillHPFAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (400, 300);
    addAndMakeVisible(freqSlider);
    freqSlider.setRange (0, 0.49);
    freqSlider.addListener (this);
    addAndMakeVisible (freqLabel);
    freqLabel.setText ("a1 cofficient", juce::dontSendNotification);
    freqLabel.attachToComponent (&freqSlider, true);
}

WillHPFAudioProcessorEditor::~WillHPFAudioProcessorEditor()
{
}

//==============================================================================
void WillHPFAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (30.0f);
    g.drawFittedText ("Will Pirkle - Simple HPF", 0, 30, getWidth(), 5, juce::Justification::centred, 1);
}

void WillHPFAudioProcessorEditor::resized()
{
    freqSlider.setBounds(100,150,250,20);
}


void WillHPFAudioProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    if (slider == &freqSlider)
    {
        audioProcessor.setCoefs(freqSlider.getValue());
    }
    
}
