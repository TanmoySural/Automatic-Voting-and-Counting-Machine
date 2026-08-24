# 🔐 **AUTOMATIC COUNTING AND VOTING MACHINE (ACVM)**

### 🗳️ Biometric Authentication • Arduino • Secure Voting Prototype

A biometric electronic voting system built with **Arduino** and an **Adafruit Fingerprint Sensor** to authenticate voters before recording their votes.

The system provides fingerprint-based verification, three-party vote counting, LED feedback, and automatic winner calculation through the Serial Monitor.

---

## 📌 About the Project

Traditional electronic voting prototypes generally rely on buttons or switches alone, which can allow unauthorized or repeated voting.

This project introduces **fingerprint authentication** into the voting process.

Before a vote is recorded, the system captures the voter's fingerprint and searches the fingerprint database. If a valid fingerprint match is found, the selected party's vote count is incremented.

The system currently supports **three parties**:

- 🅰️ Party A
- 🅱️ Party B
- 🅲 Party C

A dedicated result switch displays the final vote counts and determines the winning party.

---

## ✨ Features

- 🔐 **Fingerprint-based voter authentication**
- 🗳️ **Three-party electronic voting**
- 🔢 **Automatic vote counting**
- 💡 **LED-based voting feedback**
- 📟 **Serial Monitor output**
- 🏆 **Automatic winner detection**
- 📊 **Winning-margin calculation**
- ⚡ **Real-time vote registration**
- 🚨 **Fingerprint communication/error handling**
- 🔌 **Push-button based party selection**

---

## 🧠 How It Works

The voting process follows this workflow:

```text
                    ┌──────────────────┐
                    │  Power ON System │
                    └────────┬─────────┘
                             │
                             ▼
                 ┌───────────────────────┐
                 │ Initialize Fingerprint│
                 │       Sensor          │
                 └──────────┬────────────┘
                            │
                            ▼
                 ┌───────────────────────┐
                 │   Voter Selects       │
                 │      Party            │
                 └──────────┬────────────┘
                            │
                            ▼
                 ┌───────────────────────┐
                 │  Scan Fingerprint     │
                 └──────────┬────────────┘
                            │
                     ┌──────┴──────┐
                     │             │
                  MATCH         NO MATCH
                     │             │
                     ▼             ▼
              Register Vote     Reject Vote
                     │
                     ▼
              Update Counter
                     │
                     ▼
              LED Feedback
                     │
                     ▼
              Next Voter
                     │
                     ▼
              Result Button
                     │
                     ▼
             Calculate Winner
