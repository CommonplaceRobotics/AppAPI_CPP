# Tool Change

In most situations we recommend configuring the robot's tool statically using the igus Robot Control PC software. However, the app API supports changing the tool from iRC V15.2.0. This may be useful for use cases like the following:
* Changing tools
* Adapting the TCP offset from the robot's flange

Changing the tool will stop any running motion program. Programs may contain the tool's configuration file name, if so loading them with a differently named tool will fail.

## API

```AppClient``` provides the following methods:
* ```GetTool()``` - Gets the name of the currently configured tool configuration. Returns an empty string if no tool is configured.
* ```SetTool()``` - Loads a tool from a tool configuration file. Calling this with an empty string will remove the tool.
* ```RemoveTool()``` - Removes the configured tool.

## Hints

The tool configuration file must be present in the ```Data/Tools``` directory on the robot control. You can upload new or updated configurations using ```UploadFile()``` or via the iRC PC software.
