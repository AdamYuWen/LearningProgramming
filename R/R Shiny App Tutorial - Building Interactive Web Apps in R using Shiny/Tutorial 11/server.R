library(shiny)

shinyServer(function(input, output) {
  dataset_input <- reactive({
    switch(input$dataset,
           "iris" = iris,
           "mtcars" = mtcars,
           "trees" = trees
    )
  })

  file_ext <- reactive({
    switch(input$type,
      "Excel (CSV)" = "csv",
      "Text (TSV)" = "txt",
      "Text (Space Separated)" = "txt",
      "Doc" = "doc"
     )
  })

  # Show data table.
  output$table <- renderTable(dataset_input())

  # Download data table.
  output$download_data <- downloadHandler(
    filename = function() {
      paste(input$dataset, file_ext(), sep = ".")
    },

    content = function(file) {
      sep <- switch(input$type,
        "Excel (CSV)" = ",",
        "Text (TSV)" = "\t",
        "Text (Space Separated)" = " ",
        "Doc" = " "
      )

      # Use the parameter "file" instead of filename.
      write.table(dataset_input(), file = file, sep = sep, row.names = FALSE)
    }
  )
})
