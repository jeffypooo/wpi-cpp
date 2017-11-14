//
// Created by Jefferson Jones on 11/13/17.
//
#include <example/common/cli_args.h>
#include <io/logger.h>
#include <io/digital_in.h>
#include <io/digital_out.h>
#include <unistd.h>

#define DEFAULT_IN_PIN      37
#define DEFAULT_OUT_PIN     38
#define FLAG_IN_PIN         "-i"
#define FLAG_OUT_PIN        "-o"
#define TAG                 "DIOExample"

void ConfigureInput(int pin);

void OutputLoop(int pin);

int main(int argc, char **argv) {
    io::Setup();
    int in_pin = DEFAULT_IN_PIN;
    int out_pin = DEFAULT_OUT_PIN;
    CLIArgs args(argc, argv);
    if (HaveFlag(FLAG_IN_PIN, args)) {
        std::string i_pin_str = ArgForFlag(FLAG_IN_PIN, args);
        in_pin = std::stoi(i_pin_str);

    }
    if (HaveFlag(FLAG_OUT_PIN, args)) {
        std::string o_pin_str = ArgForFlag(FLAG_OUT_PIN, args);
        out_pin = std::stoi(o_pin_str);
    }
    ConfigureInput(in_pin);
    OutputLoop(out_pin);
}

void ConfigureInput(int pin) {
    io::LogV(TAG, "Creating input...");
    io::DigitalIn input(pin);
    io::LogV(TAG, "Attaching input interrupt handler...");
    std::function<void(io::DigitalIn *in)> input_irq = [](io::DigitalIn *in) {
        io::LogV(TAG, "INPUT IRQ");
    };
    io::LogV(TAG, "Input ready.");
}

void OutputLoop(int pin) {
    io::LogV(TAG, "Creating output...");
    io::DigitalOut output(pin);
    io::LogV(TAG, "Output ready.");
    // Toggle at ~1KHz
    while (true) {
        output.Write(1);
        usleep(500);
        output.Write(0);
        usleep(500);

    }
}
