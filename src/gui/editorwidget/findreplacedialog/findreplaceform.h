/*
 * Copyright (C) 2009  Lorenzo Bettini <http://www.lorenzobettini.it>
 * See COPYING file that comes with this distribution
 */
 
/***************************************************************************
 *   Modified 2012 by santiago González                                    *
 *   santigoro@gmail.com                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/
 
#ifndef FINDREPLACEFORM_H
#define FINDREPLACEFORM_H

#include <QWidget>
#include <QTextCursor>

#include "findreplace_global.h"

namespace Ui {
    class FindReplaceFORM;
}

class QTextEdit;
class QSettings;

/**
  * The form for the find/replace dialog.  The form presents the typical
  * widgets you find in standard find/replace dialogs, and it acts on a QTextEdit.
  *
  * \image html Screenshot-FindReplace.png
  *
  * You need to set the QTextEdit explicitly, using the method setTextEdit(QTextEdit *textEdit).
  *
  * For instance
  * \code
  * m_findReplaceDialog = new FindReplaceDialog(this);
  * m_findReplaceDialog->setModal(false);
  * m_findReplaceDialog->setTextEdit(ui->textEdit);
  * \endcode
  *
  * The find functionalities is available even if the find dialog is not shown: if something
  * to search for was already specified, the application can call the methods findNext() and
  * findPrev() (e.g., by connecting them to menu items).
  *
  * In case a regular expression is used as the search term, the form also checks whether the
  * expression is a valid regular expression (You may want to take a look at the syntax of regular expressions:
  * http://doc.trolltech.com/QRegExp.html).
  *
  * The form provides also functionalities to save and restore its state using a QSettings object (i.e.,
  * the last word searched for, the options of the form, etc.) via the methods writeSettings()
  * and readSettings().
  *
  * You can take a look at the \ref examples page.
  */
class FindReplaceForm : public QWidget {
    Q_OBJECT
public:
    FindReplaceForm(QWidget *parent = 0);
    virtual ~FindReplaceForm();

    /**
      * Associates the text editor where to perform the search
      * @param textEdit_
      */
    void setTextEdit(CodeEditor *textEdit_);
    
    void setTextToFind( QString text);

    /// hides replace widgets from the form
    void hideReplaceWidgets();

    /**
      * Writes the state of the form to the passed settings.
      * @param settings
      * @param prefix the prefix to insert in the settings
      */
    virtual void writeSettings(QSettings &settings, const QString &prefix = "FindReplaceDialog");

    /**
      * Reads the state of the form from the passed settings.
      * @param settings
      * @param prefix the prefix to look for in the settings
      */
    virtual void readSettings(QSettings &settings, const QString &prefix = "FindReplaceDialog");

public slots:
    /**
     * performs the find task
     * @param down whether to find the next or the previous
     * occurrence
     */
    void find(bool down);

    /**
     * Finds the next occurrence
     */
    void find();

    /**
     * Finds the next occurrence
     */
    void findNext() { find(true); }

    /**
     * Finds the previous occurrence
     */
    void findPrev() { find(false); }

    /**
      * Replaces the found occurrences and goes to the next occurrence
      */
    void replace();

    /**
      * Replaces all the found occurrences
      */
    void replaceAll();

protected:
    void changeEvent(QEvent *e);

    /// shows an error in the dialog
    void showError(const QString &error);

    /// shows a message in the dialog
    void showMessage(const QString &message);

protected slots:
    /// when the text edit contents changed
    void textToFindChanged();

    /// checks whether the passed text is a valid regexp
    void validateRegExp(const QString &text);

    /// the regexp checkbox was selected
    void regexpSelected(bool sel);

protected:
    Ui::FindReplaceFORM* ui;

    /// for searching into the text
    QTextCursor m_textCursor;

    /// the text editor (possibly) associated with this form
    CodeEditor* m_textEdit;
};

#endif // FINDREPLACEFORM_H
