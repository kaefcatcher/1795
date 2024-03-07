import subprocess
import Tkinter as tk
import ttk

def main():
    root = tk.Tk()
    root.title("Configuration Parameters")


    canvas = tk.Canvas(root)
    canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=tk.TRUE)

    scrollbar = ttk.Scrollbar(root, orient="vertical", command=canvas.yview)
    scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
    canvas.configure(yscrollcommand=scrollbar.set)


    frame = tk.Frame(canvas)
    canvas.create_window((0, 0), window=frame, anchor=tk.NW)

    def on_configure(event):
        canvas.configure(scrollregion=canvas.bbox("all"))

    frame.bind("<Configure>", on_configure)


    parameters = {
        "Vehicles": [4],
        "pscchLength": [8],
        "mcs": [13],
        "ueTxPower": [23.0],
        "simTime": [30],
        "seed": [867],
        "runNo": [1],
        "randomV2VSelection": ["false", "true"],
        "noIBE": ["true", "false"],
        "SubChannel": [10],
        "ChannelBW": [10],
        "VariableSize": ["false", "true"],
        "Dynamic": ["false", "true"],
        "Adaptive": ["false", "true"],
        "ReTx": ["false", "true"],
        "ReEvaluation": ["false", "true"],
        "AllSlots": ["false", "true"],
        "UMH": ["false", "true"],
        "RSRP": [-128.0],
        "PDB": [0],
        "Numerology": [0],
        "Periodic": ["false", "true"],
        "Aperiodic": ["false", "true"],
        "Mixed": ["false", "true"],
        "Percentage": [0],
        "ETSI": ["false", "true"],
        "AvgRRI": ["false", "true"],
        "FreqReuse": ["false", "true"],
        "ReuseDist": [0],
        "tracefile": [""]
    }


    def execute_command():
        config = {}
        for param, entry in entry_widgets.items():
            value = entry.get()
            if value:
                config[param] = value


        command = "./waf --run \"scratch/updated_highway"
        for param, value in config.items():
            command += " --{}={}".format(param, value)
        command += "\""


        print("Running command:", command)
        subprocess.call(command, shell=True)




    entry_widgets = {}
    row = 0
    for param, _ in parameters.items():
        label = tk.Label(frame, text=param)
        label.grid(row=row, column=0, padx=5, pady=5, sticky=tk.W)
        entry = ttk.Entry(frame)
        entry.grid(row=row, column=1, padx=5, pady=5, sticky=tk.EW)
        entry_widgets[param] = entry
        row += 1


    execute_button = tk.Button(root, text="Execute Command", command=execute_command)
    execute_button.pack(padx=10, pady=10)

    root.mainloop()

if __name__ == "__main__":
    main()
